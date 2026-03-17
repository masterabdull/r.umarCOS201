#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int loadData(int ids[], int scores[]) {
    ifstream file("scores.csv");
    if (!file) {
        cout << "Could not open scores.csv\n";
        return 0;
    }

    string header;
    getline(file, header);

    int count = 0;
    while (file) {
        char comma;
        file >> ids[count] >> comma >> scores[count];
        if (file) count++;
    }

    file.close();
    return count;
}

void printAll(int ids[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "StudentID: " << ids[i] << "   Score: " << scores[i] << "\n";
    }
}

void computeStats(int scores[], int size, double &average, int &minScore, int &maxScore) {
    int sum = 0;
    minScore = scores[0];
    maxScore = scores[0];
    for (int i = 0; i < size; i++) {
        sum += scores[i];
        if (scores[i] < minScore) minScore = scores[i];
        if (scores[i] > maxScore) maxScore = scores[i];
    }
    average = (double)sum / size;
}

void computeGrades(int scores[], int size, int &A, int &B, int &C, int &D, int &F) {
    A = B = C = D = F = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] >= 70) A++;
        else if (scores[i] >= 60) B++;
        else if (scores[i] >= 50) C++;
        else if (scores[i] >= 45) D++;
        else F++;
    }
}

int pickPassing(int ids[], int scores[], int size) {
    int passing[100];
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] >= 50) passing[count++] = i;
    }
    if (count == 0) return -1;
    int r = rand() % count;
    return passing[r];
}

void saveSummary(double average, int minScore, int maxScore,
                 int A, int B, int C, int D, int F, int total) {
    ofstream file("summary.csv");
    file << "Metric,Value\n";
    file << "Number of Students," << total << "\n";
    file << "Average Score," << average << "\n";
    file << "Minimum Score," << minScore << "\n";
    file << "Maximum Score," << maxScore << "\n";
    file << "A Count," << A << "\n";
    file << "B Count," << B << "\n";
    file << "C Count," << C << "\n";
    file << "D Count," << D << "\n";
    file << "F Count," << F << "\n";
    file.close();
}

int main() {
    srand(time(0));

    int ids[100], scores[100];
    double average;
    int minScore, maxScore;
    int A, B, C, D, F;

    int total = loadData(ids, scores);

    cout << "Total students: " << total << "\n\n";
    printAll(ids, scores, total);

    computeStats(scores, total, average, minScore, maxScore);
    cout << "\nAverage: " << average << "\n";
    cout << "Min: " << minScore << "\n";
    cout << "Max: " << maxScore << "\n";

    computeGrades(scores, total, A, B, C, D, F);
    cout << "\nGrades:\nA: " << A << "\nB: " << B << "\nC: " << C
         << "\nD: " << D << "\nF: " << F << "\n";

    int lucky = pickPassing(ids, scores, total);
    cout << "\nRandom  Lucky passing student:\n";
    if (lucky == -1) cout << "Nobody passed olololo \n";
    else cout << "StudentID: " << ids[lucky] << "  Score: " << scores[lucky] << "\n";

    saveSummary(average, minScore, maxScore, A, B, C, D, F, total);
    cout << "\nsummary.csv saved\n";

    return 0;
}
