#include <stdio.h>

// Function declarations
void displayMenu();
int getVote(int voterNumber);
void displayResults(int candidate1Votes, int candidate2Votes, int candidate3Votes);
void determineWinner(int candidate1Votes, int candidate2Votes, int candidate3Votes);

int main() {
    int candidate1Votes = 0, candidate2Votes = 0, candidate3Votes = 0;
    int totalVotes, vote;
    
    // Display the menu for available candidates
    displayMenu();

    // Prompt the user for the total number of voters
    printf("Enter the number of voters: ");
    while (scanf("%d", &totalVotes) != 1 || totalVotes <= 0) {
        printf("Invalid input. Please enter a positive integer for the number of voters: ");
        while(getchar() != '\n'); // Clear the buffer
    }

    // Collect votes for each voter
    for (int i = 1; i <= totalVotes; i++) {
        vote = getVote(i);  // Get a valid vote from the current voter
        if (vote == 1) {
            candidate1Votes++;
        } else if (vote == 2) {
            candidate2Votes++;
        } else if (vote == 3) {
            candidate3Votes++;
        }
    }

    // Display the voting results
    displayResults(candidate1Votes, candidate2Votes, candidate3Votes);

    // Determine the winner or check if there's a tie
    determineWinner(candidate1Votes, candidate2Votes, candidate3Votes);

    return 0;
}

// Function to display the candidates' menu
void displayMenu() {
    printf("\nWelcome to the Voting System!\n");
    printf("We have the following candidates:\n");
    printf("1. Candidate 1\n");
    printf("2. Candidate 2\n");
    printf("3. Candidate 3\n");
}

// Function to get and validate a valid vote from a voter
int getVote(int voterNumber) {
    int vote;
    
    while (1) {
        printf("Voter %d, please enter your vote (1, 2, or 3): ", voterNumber);
        if (scanf("%d", &vote) != 1) {
            while(getchar() != '\n'); // Clear the buffer
            printf("Invalid input. Please enter a valid vote (1, 2, or 3).\n");
            continue;
        }
        if (vote >= 1 && vote <= 3) {
            break;  // Valid vote
        } else {
            printf("Invalid vote! Please vote for 1, 2, or 3.\n");
        }
    }

    return vote;
}

// Function to display the total votes for each candidate
void displayResults(int candidate1Votes, int candidate2Votes, int candidate3Votes) {
    printf("\nVoting Results:\n");
    printf("Candidate 1: %d votes\n", candidate1Votes);
    printf("Candidate 2: %d votes\n", candidate2Votes);
    printf("Candidate 3: %d votes\n", candidate3Votes);
}

// Function to determine the winner based on the vote counts
void determineWinner(int candidate1Votes, int candidate2Votes, int candidate3Votes) {
    if (candidate1Votes > candidate2Votes && candidate1Votes > candidate3Votes) {
        printf("\nWinner: Candidate 1\n");
    } else if (candidate2Votes > candidate1Votes && candidate2Votes > candidate3Votes) {
        printf("\nWinner: Candidate 2\n");
    } else if (candidate3Votes > candidate1Votes && candidate3Votes > candidate2Votes) {
        printf("\nWinner: Candidate 3\n");
    } else {
        printf("\nIt's a tie!\n");
    }
}
