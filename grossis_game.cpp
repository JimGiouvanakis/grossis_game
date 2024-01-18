#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Question {
    std::string questionText;
    char correctAnswer;
    std::string optionA, optionB, optionC, optionD;
};

std::vector<Question> questions;

std::string getFullAnswer(char answerCode, const Question& question);

void drawBox(const std::string& message) {
    std::cout << "+";
    for (size_t i = 0; i < message.length() + 4; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    std::cout << "|  " << message << "  |" << std::endl;

    std::cout << "+";
    for (size_t i = 0; i < message.length() + 4; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}

void addQuestions() {
    // Initialize questions with correct answers
    Question q1 = {"Who holds the record for the most goals scored in a single UEFA Champions League season?", 'C', "Lionel Messi", "Cristiano Ronaldo", "Robert Lewandowski", "Raul"};
    Question q2 = {"Which club has won the UEFA Champions League most times as of 2022?", 'B', "FC Barcelona", "Real Madrid", "AC Milan", "Liverpool"};
    Question q3 = {"In which city is the UEFA Champions League Final traditionally held?", 'C', "London", "Paris", "Istanbul", "Rome"};
    Question q4 = {"Who is the all-time top scorer in the history of the UEFA Champions League?", 'B', "Lionel Messi", "Cristiano Ronaldo", "Raul", "Karim Benzema"};
    Question q5 = {"Which player holds the record for the most assists in a single UEFA Champions League season?", 'B', "Lionel Messi", "Kevin De Bruyne", "Neymar", "Zinedine Zidane"};

    // Add questions to the vector
    questions.push_back(q1);
    questions.push_back(q2);
    questions.push_back(q3);
    questions.push_back(q4);
    questions.push_back(q5);
}

bool isAnswerCorrect(const std::string& userAnswer, const Question& question) {
    return userAnswer[0] == question.correctAnswer;
}

std::string getFullAnswer(char answerCode, const Question& question) {
    switch (answerCode) {
        case 'A':
            return question.optionA;
        case 'B':
            return question.optionB;
        case 'C':
            return question.optionC;
        case 'D':
            return question.optionD;
        default:
            return "Unknown Option";
    }
}

void displayQuestions() {
    int score = 0; // Initialize the score to 0

    drawBox("GROSSIS'S GAME");

    for (const auto& question : questions) {
        // Display the question and options
        std::cout << "Question: " << question.questionText << std::endl;
        std::cout << "Options: " << std::endl;
        std::cout << "A. " << question.optionA << std::endl;
        std::cout << "B. " << question.optionB << std::endl;
        std::cout << "C. " << question.optionC << std::endl;
        std::cout << "D. " << question.optionD << std::endl;

        std::string userAnswer;
        while (true) {
            std::cout << "Your answer: ";
            std::getline(std::cin, userAnswer);

            // Validate user input
            if (userAnswer.length() == 1 && (userAnswer[0] == 'A' || userAnswer[0] == 'B' || userAnswer[0] == 'C' || userAnswer[0] == 'D')) {
                break; // Exit the loop if the input is valid
            } else {
                std::cout << "Invalid input. Please choose from options A, B, C, or D." << std::endl;
            }
        }

        if (isAnswerCorrect(userAnswer, question)) {
            std::cout << "Correct! Well done!" << std::endl;
            score++; // Increment the score for a correct answer
        } else {
            std::cout << "Incorrect. The correct answer is option " << question.correctAnswer << ": " << getFullAnswer(question.correctAnswer, question) << std::endl;
        }
    }

    std::cout << "Your final score: " << score << " out of " << questions.size() << std::endl;
}

int main() {
    addQuestions();
    displayQuestions();

    return 0;
}
