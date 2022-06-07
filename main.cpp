#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#define FAIL 37
#define MULTIPLE 5
#define MINGRADE 0
#define MAXGRADE 100

/*
 * Rounds up grades to the closest greater multiple of 5 IF the grade is no more than 2 points away
 */

vector<int> gradingStudents(vector<int> grades) {
    vector <int> roundedGrades;

    //Count Controlled loop reviewing each grade in the passed array
    for (int i = 0; i < grades.size(); i++) {
        int currentGrade = 0;
        int roundedGrade = 0;
        int nearestRoundUp = 0;

        currentGrade = grades[i];

        // If the grade is less than 37 OR 100, do not process, but add to roundedGrades [i]
        if (currentGrade <= FAIL || currentGrade == MAXGRADE) {
            roundedGrades.push_back(currentGrade);
        }
        // If the grade is >= 38 AND less than 100, check to see if
        // next multiple of 5 - grade[i] < 3 (i.e. 38 -> 40; 40 - 38 = 2; 2 < 3; so round 38 to 40)
        // Add to roundedGrades[i].
        else if (currentGrade > FAIL && currentGrade < MAXGRADE) {
            nearestRoundUp = ((MULTIPLE - (currentGrade % MULTIPLE)) + currentGrade);
        }
        else {
            cout << "Error: grade " << currentGrade << " outside expected range" << endl;
        }
    }

    return roundedGrades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}