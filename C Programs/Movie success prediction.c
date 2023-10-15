#include <stdio.h>

int main() {
    // Define hypothetical features for movie success prediction
    int budget, cast_popularity, marketing_budget;
    
    // Get user input for movie features
    printf("Enter movie budget (in millions): ");
    scanf("%d", &budget);
    
    printf("Enter cast popularity (1-10): ");
    scanf("%d", &cast_popularity);
    
    printf("Enter marketing budget (in millions): ");
    scanf("%d", &marketing_budget);
    
    // Simple success prediction model (hypothetical)
    if (budget >= 50 && cast_popularity >= 7 && marketing_budget >= 20) {
        printf("Prediction: This movie is likely to be successful!\n");
    } else {
        printf("Prediction: This movie may not be very successful.\n");
    }
    
    return 0;
}
