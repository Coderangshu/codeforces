#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    string line;

    int T; 
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N;  
        cin >> N;
        
        double minSpeed = 1e18;
        double maxSpeed = 0.0;
        
        bool possible = true;
        
        for (int i = 1; i <= N; i++) {
            int Ai, Bi;
            cin >> Ai >> Bi;
            
            double lowerBound = double(i) / Bi;
            double upperBound = double(i) / Ai;
            
            maxSpeed = max(maxSpeed, lowerBound);    
            minSpeed = min(minSpeed, upperBound);   
            
            // If the bounds are invalid, it's impossible
            if (maxSpeed > minSpeed) {
                possible = false;
            }
        }
        
        // Output the result for this test case
        cout << "Case #" << t << ": ";
        if (possible) {
            cout << fixed << setprecision(6) << maxSpeed << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}

