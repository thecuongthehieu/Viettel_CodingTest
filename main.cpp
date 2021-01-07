#include <bits/stdc++.h>

using namespace std;

/**
    1. Assumtion: (a, b) is valid iff b > a;
    2. (a, a + 1) has distance equals 0;
*/

/*  
    Interval Struct
        val : a part of startpoint and endpoint
        distance: distace of interval
*/

struct Interval {
    pair<int, int> val;
    int distance;
};

/*
    Global variable:
        1. N : Input number
        2. intervalSet  : randomly generated set of intervals.
*/
int N;
vector<Interval> intervalSet;


/* Compare two interval by distance */
bool compareIntervalByDist(Interval v1, Interval v2) {
    return v1.distance < v2.distance;
}

/* Compare two interval by endpoint */
bool compareIntervalByEndpoint(Interval v1, Interval v2) {
    return v1.val.second < v2.val.second;
}

/* Get a random number between min and max */
int random(int max, int min) {
    int range = max - min + 1;
    return rand() % range + min;
}

/* Get number of negative numbers subject to:
   Greater 30/100 of n are negative numbers.
*/
int getNumOfNegativeNumber(int n) {
    /* minimum number of negative numbers */
    int temp = ceil(n * 0.3); 

    /* plus random addition */
    return temp + (rand() % (n - temp + 1));
}

void partI() {
    cout << N << endl;
    int numNegative = getNumOfNegativeNumber(N);

    /* Generate greater than 30/100 */
    for (int i = 0; i < numNegative; ++i) {
        struct Interval interval;
        interval.val.first = (-rand() - 1) - 1;
        interval.val.second = random(RAND_MAX, interval.val.first + 1);
        interval.distance = interval.val.second - interval.val.first - 1;

        intervalSet.push_back(interval);
    }

    /* Generate the other */
    for (int i = 0; i < (N - numNegative); ++i) {
        struct Interval interval;
        interval.val.first = rand() - 1;
        interval.val.second = random(RAND_MAX, interval.val.first + 1);
        interval.distance = interval.val.second - interval.val.first - 1;

        intervalSet.push_back(interval);
    }


    for (int i = 0; i < N; ++i) {
        cout << "(" << intervalSet[i].val.first << "; " << intervalSet[i].val.second << ")" << endl;
    }
}

void partII() {
    //cout << "PART II" << endl;
    vector<Interval> maxDisjointSet;
    
    /* Sorted increment by endpoint */
    sort(intervalSet.begin(), intervalSet.end(), compareIntervalByEndpoint);
    maxDisjointSet.push_back(intervalSet[0]);
    
    int r1 = intervalSet[0].val.second;

    for (int i = 1; i < N; ++i) {
        int l1 = intervalSet[i].val.first;
        int r2 = intervalSet[i].val.second;

        if (l1 >= r1) {
            maxDisjointSet.push_back(intervalSet[i]);
            r1 = r2;
        }
    } 

     /* Sorted increment by distance */
    sort(maxDisjointSet.begin(), maxDisjointSet.end(), compareIntervalByDist);

    for (int i = 0; i < maxDisjointSet.size(); ++i) {
        cout << "(" << maxDisjointSet[i].val.first << "; " << maxDisjointSet[i].val.second << ")" << endl;
    }
}

/* 
    MAIN 
*/
int main() {
    /* Take input */
    cout << "Nhap so khoang nguyen N: ";
    cin >> N;

    /* Initialize random seed: */
    srand (time(NULL));


    /* PART I */
    cout << "PART I" << endl;
    partI();

    /* PART II */
    cout << "PART II" << endl;
    partII();
}