#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct User {
    char name[50];
    struct User* next;
    struct Edge* connections;
} User;


typedef struct Edge {
    User* user;
    struct Edge* next;
} Edge;


typedef struct Graph {
    User* users;
    int num_users;
} Graph;

Graph* graph;


User* createUser(const char* name) {
    User* user = (User*)malloc(sizeof(User));
    strcpy(user->name, name);
    user->next = NULL;
    user->connections = NULL; 
    return user;
}



Graph* createGraph(int num_users) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->users = NULL;
    graph->num_users = num_users;
    for (int i = 0; i < num_users; i++) {
        char default_name[50];
        snprintf(default_name, sizeof(default_name), "User%d", i + 1); 
        User* user = createUser(default_name);
        user->next = graph->users;
        graph->users = user;
    }
    return graph;
}


User* searchUserInGraph(Graph* graph, const char* username) {
    User* user = graph->users;
    while (user) {
        if (strcmp(user->name, username) == 0) {
            return user;
        }
        user = user->next;
    }
    return NULL;
}


void addUser(Graph* graph, const char* name) {
    User* newUser = createUser(name);
    newUser->next = graph->users;
    graph->users = newUser;
    printf("User '%s' added.\n", name);
}



void addConnection(Graph* graph, const char* user1, const char* user2) {
    User* u1 = searchUserInGraph(graph, user1);
    User* u2 = searchUserInGraph(graph, user2);

    if (u1 == NULL || u2 == NULL) {
        printf("User not found!\n");
        return;
    }

    
    Edge* edge1 = (Edge*)malloc(sizeof(Edge));
    edge1->user = u2;
    edge1->next = u1->connections;
    u1->connections = edge1;

    Edge* edge2 = (Edge*)malloc(sizeof(Edge));
    edge2->user = u1;
    edge2->next = u2->connections;
    u2->connections = edge2;
    
    printf("Connection between '%s' and '%s' made.\n", user1, user2);
}


void displayGraph(Graph* graph, GtkTextBuffer* buffer) {
    User* user = graph->users;
    while (user) {
        gchar* text = g_strdup_printf("User: %s, Connections:", user->name);
        gtk_text_buffer_insert_at_cursor(buffer, text, -1);
        g_free(text);

        Edge* edge = user->connections;
        while (edge) {
            gchar* edge_text = g_strdup_printf(" %s", edge->user->name);
            gtk_text_buffer_insert_at_cursor(buffer, edge_text, -1);
            g_free(edge_text);
            edge = edge->next;
        }
        gtk_text_buffer_insert_at_cursor(buffer, "\n", -1);

        user = user->next;
    }
}


void addUserCallback(GtkWidget* widget, gpointer data) {
    const char* username = gtk_entry_get_text(GTK_ENTRY(data));
    if (strlen(username) > 0) {
        addUser(graph, username);
        
    }
}


void addConnectionCallback(GtkWidget* widget, gpointer data) {
    const char* connection = gtk_entry_get_text(GTK_ENTRY(data));
    char user1[50], user2[50];

    
    if (sscanf(connection, "%s %s", user1, user2) == 2) {
        
        User* u1 = searchUserInGraph(graph, user1);
        User* u2 = searchUserInGraph(graph, user2);

        if (u1 != NULL && u2 != NULL) {
            addConnection(graph, user1, user2);
            
        } else {
            printf("User not found!\n");
        }
    } else {
        printf("Invalid input. Use 'User1 User2' format.\n");
    }
}


void displayGraphCallback(GtkWidget* widget, gpointer data) {
    GtkWidget* window;
    GtkWidget* text_view;
    GtkWidget* scrolled_window;
    GtkTextBuffer* buffer;

    gtk_init(NULL, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Social Network");

    text_view = gtk_text_view_new();
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    gtk_text_buffer_set_text(buffer, "", -1);

    displayGraph(graph, buffer);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);

    gtk_main();
}


void cleanupGraph(Graph* graph) {
    User* user = graph->users;
    while (user) {
        Edge* edge = user->connections;
        while (edge) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }

        User* temp_user = user;
        user = user->next;
        free(temp_user);
    }

    free(graph);
}

int main(int argc, char* argv[]) {
    GtkWidget* window;
    GtkWidget* vbox;
    GtkWidget* label1;
    GtkWidget* label2;
    GtkWidget* entry1;
    GtkWidget* entry2;
    GtkWidget* addUserButton;
    GtkWidget* addConnectionButton;
    GtkWidget* displayNetworkButton;

    
    gtk_init(&argc, &argv);

    
    graph = createGraph(100);

    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Social Network");

    
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    
    label1 = gtk_label_new("Enter username to add:");
    entry1 = gtk_entry_new();
    label2 = gtk_label_new("Enter User1 User2 for connection:");
    entry2 = gtk_entry_new();
    addUserButton = gtk_button_new_with_label("Add User");
    addConnectionButton = gtk_button_new_with_label("Create Connection");

    
    g_signal_connect(G_OBJECT(addUserButton), "clicked", G_CALLBACK(addUserCallback), entry1);
    g_signal_connect(G_OBJECT(addConnectionButton), "clicked", G_CALLBACK(addConnectionCallback), entry2);

    
    displayNetworkButton = gtk_button_new_with_label("Display Network");
    g_signal_connect(G_OBJECT(displayNetworkButton), "clicked", G_CALLBACK(displayGraphCallback), NULL);

    
    gtk_box_pack_start(GTK_BOX(vbox), label1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), entry1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), addUserButton, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), label2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), entry2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), addConnectionButton, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), displayNetworkButton, FALSE, FALSE, 0);

    
    gtk_widget_show_all(window);

    
    gtk_main();

    
    cleanupGraph(graph);

    return 0;
}
