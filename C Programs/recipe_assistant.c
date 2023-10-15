#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INGREDIENTS 10

struct Ingredient {
    char name[50];
    struct Ingredient* next;
};

struct Recipe {
    char name[50];
    struct Ingredient* ingredients;
    char instructions[500];
    struct Recipe* next;
};

struct RecipeAssistant {
    struct Recipe* recipes;
};

// Function to create a new ingredient
struct Ingredient* create_ingredient(const char* name) {
    struct Ingredient* ingredient = (struct Ingredient*)malloc(sizeof(struct Ingredient));
    if (ingredient == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    strncpy(ingredient->name, name, sizeof(ingredient->name));
    ingredient->next = NULL;
    return ingredient;
}

// Function to create a new recipe
struct Recipe* create_recipe(const char* name, const char* instructions) {
    struct Recipe* recipe = (struct Recipe*)malloc(sizeof(struct Recipe));
    if (recipe == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    strncpy(recipe->name, name, sizeof(recipe->name));
    strncpy(recipe->instructions, instructions, sizeof(recipe->instructions));
    recipe->ingredients = NULL;
    recipe->next = NULL;
    return recipe;
}

// Function to add an ingredient to a recipe
void add_ingredient(struct Recipe* recipe, const char* ingredient_name) {
    struct Ingredient* ingredient = create_ingredient(ingredient_name);
    ingredient->next = recipe->ingredients;
    recipe->ingredients = ingredient;
}

// Function to add a recipe to the assistant
void add_recipe(struct RecipeAssistant* assistant, const char* name, const char* instructions) {
    struct Recipe* recipe = create_recipe(name, instructions);
    recipe->next = assistant->recipes;
    assistant->recipes = recipe;
}

// Function to find and return a recipe by name
struct Recipe* find_recipe(struct RecipeAssistant* assistant, const char* name) {
    struct Recipe* current = assistant->recipes;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to list all recipes
void list_recipes(struct RecipeAssistant* assistant) {
    struct Recipe* current = assistant->recipes;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Ingredients: ");
        struct Ingredient* current_ingredient = current->ingredients;
        while (current_ingredient != NULL) {
            printf("%s, ", current_ingredient->name);
            current_ingredient = current_ingredient->next;
        }
        printf("\nInstructions: %s\n", current->instructions);
        current = current->next;
    }
}


int main() {
    struct RecipeAssistant assistant;
    assistant.recipes = NULL;

    char user_input[100];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Recipe\n");
        printf("2. Search Recipe\n");
        printf("3. List Recipes\n");
        printf("4. Quit\n");
        printf("Select an option (1/2/3/4): ");
        fgets(user_input, sizeof(user_input), stdin);
        int choice = atoi(user_input);

        switch (choice) {
            case 1: {
                printf("\nEnter Recipe Name: ");
                fgets(user_input, sizeof(user_input), stdin);
                user_input[strcspn(user_input, "\n")] = '\0';  // Remove newline character
                char recipe_name[50];
                strncpy(recipe_name, user_input, sizeof(recipe_name));

                printf("Enter Instructions: ");
                fgets(user_input, sizeof(user_input), stdin);
                user_input[strcspn(user_input, "\n")] = '\0';  // Remove newline character

                add_recipe(&assistant, recipe_name, user_input);

                printf("\nEnter Ingredients (enter 'done' to finish adding ingredients):\n");
                while (1) {
                    fgets(user_input, sizeof(user_input), stdin);
                    user_input[strcspn(user_input, "\n")] = '\0';  // Remove newline character
                    if (strcmp(user_input, "done") == 0) {
                        break;
                    }
                    add_ingredient(assistant.recipes, user_input);
                }

                printf("Recipe added successfully!\n");
                break;
            }
            case 2: {
                printf("\nEnter Recipe Name to Search: ");
                fgets(user_input, sizeof(user_input), stdin);
                user_input[strcspn(user_input, "\n")] = '\0';  // Remove newline character

                struct Recipe* found_recipe = find_recipe(&assistant, user_input);
                if (found_recipe != NULL) {
                    printf("\nRecipe for %s:\n", found_recipe->name);
                    printf("Ingredients: ");
                    struct Ingredient* current_ingredient = found_recipe->ingredients;
                    while (current_ingredient != NULL) {
                        printf("%s, ", current_ingredient->name);
                        current_ingredient = current_ingredient->next;
                    }
                    printf("\nInstructions: %s\n", found_recipe->instructions);
                } else {
                    printf("\nRecipe for %s not found.\n", user_input);
                }
                break;
            }
            case 3:
                printf("\nAvailable recipes:\n");
                list_recipes(&assistant);
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}
