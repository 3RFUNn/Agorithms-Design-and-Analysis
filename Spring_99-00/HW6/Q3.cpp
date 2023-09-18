#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       cout.tie(NULL);

    int start, final, number_of_turn;
    vector<int> turns1_2, turns2_3, turns3_4;
    vector<int> dis1_2, dis2_3, dis3_4;
    int min_distance = INT_MAX;

    cin >> start;

    cin >> final;

    cin >> number_of_turn;

    for (long i = 0; i < number_of_turn; i++) {
        long xi, xj, y;

        cin >> xi;

        cin >> xj;

        cin >> y;

        if ((xi == 1 && xj == 2) || (xi == 2 && xj == 1)) {
            turns1_2.push_back(y);
        }
        else if ((xi == 2 && xj == 3) || (xi == 3 && xj == 2)) {
            turns2_3.push_back(y);
        }
        else if ((xi == 3 && xj == 4) || (xi == 4 && xj == 3)) {
            turns3_4.push_back(y);
        }
    }

    for (long i = 0; i < turns1_2.size(); i++) {
        if ((turns1_2[i] - start + 1) > 0)
            dis1_2.push_back(turns1_2[i] - start + 1);
        else
            dis1_2.push_back(INT_MAX);

    }
    for (long i = 0; i < turns2_3.size(); i++) {
        dis2_3.push_back(INT_MAX);
    }
    for (long i = 0; i < turns3_4.size(); i++) {
        dis3_4.push_back(INT_MAX);
    }

    for (long i = 0; i < dis2_3.size(); i++) {
        for (long j = 0; j < dis1_2.size(); j++) {
            if ((dis2_3[i] > dis1_2[j] + turns1_2[j] - turns2_3[i] + 1) && (turns1_2[j] - turns2_3[i] >= 0)) {
                dis2_3[i] = dis1_2[j] + turns1_2[j] - turns2_3[i] + 1;
            }
        }
    }
    for (long i = 0; i < dis3_4.size(); i++) {
        for (long j = 0; j < dis2_3.size(); j++) {
            if ((dis3_4[i] > dis2_3[j] + turns3_4[i] - turns2_3[j] + 1) && (turns3_4[i] - turns2_3[j] >= 0)) {
                dis3_4[i] = dis2_3[j] + turns3_4[i] - turns2_3[j] + 1;
            }
        }
    }
    for (long i = 0; i < dis3_4.size(); i++) {
        if ((min_distance > dis3_4[i] + turns3_4[i] - final) && (turns3_4[i] - final >= 0)) {
            min_distance = dis3_4[i] + turns3_4[i] - final;
        }
    }
    if (min_distance == INT_MAX)
        min_distance = -1;

    cout << min_distance;



    return 0;
}
