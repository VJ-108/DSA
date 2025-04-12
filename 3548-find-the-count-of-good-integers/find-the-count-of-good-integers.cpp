class Solution {
    // Define a long long type alias for easier use
    #define ll long long
    
    // Variable to store the number of k-palindromes found
    ll k_palindromes = 0;

    // A set to keep track of already processed numbers to avoid duplicates
    unordered_set<ll> done;

    // Precomputed factorial values for efficient calculation of permutations
    vector<ll> fact;

    // Precompute factorials for numbers 0 to 10
    void precomputeFactorial(int& n) {
        fact[0] = 1;
        fact[1] = 1;
        for (ll i = 2; i <= 10; ++i) {
            fact[i] = i * fact[i - 1];
        }
    }

    // Function to count the total number of permutations given the frequency of digits
    ll countAllPermutations(vector<ll>& freq, int n) {
        // Start with the factorial of n (total length)
        ll count = fact[n];
        
        // Divide by the factorial of each digit's frequency to account for repetitions
        for (int i = 0; i <= 9; ++i) {
            count /= fact[freq[i]];
        }
        
        return count;
    }

    // Function to calculate all valid arrangements of the number
    ll allArrangements(string number, int& n) {
        sort(number.begin(), number.end());
        
        // If the number has already been processed, skip it
        if (done.count(stoll(number))) {
            return 0;
        }

        // Insert the current number into the done set to prevent duplicates
        done.insert(stoll(number));

        // Create a frequency vector for the digits 0-9
        vector<ll> freq(10);
        for (char& c : number) {
            freq[c - '0']++;
        }

        // Calculate the total number of permutations
        ll total_permutations = countAllPermutations(freq, n);
        
        // Calculate invalid permutations (those with leading zeroes)
        ll invalid_permutations = 0;
        if (freq[0] > 0) {
            freq[0]--;
            invalid_permutations = countAllPermutations(freq, n - 1);
        }

        // Return the valid permutations (total - invalid)
        return total_permutations - invalid_permutations;
    }

    // Function to check if a number is divisible by k
    bool isKPalindrome(string& number, int& n, int& k) {
        return (stoll(number) % k == 0);
    }

    // Recursive function to generate palindrome numbers
    void generatePalindromes(int pos, int& n, string& number, int& k) {
        // Base case: If we've reached the middle of the number
        if (pos >= (n + 1) / 2) {
            // If the palindrome is divisible by k, count its valid permutations
            if (isKPalindrome(number, n, k)) {
                k_palindromes += allArrangements(number, n);
            }
            return;
        }

        // Start from '1' for the first position to avoid leading zeros
        char start = (pos == 0) ? '1' : '0';

        // Try all possible digits for the current position (from start to '9')
        while (start <= '9') {
            number[pos] = start;
            number[n - pos - 1] = start;
            // Recurse to the next position
            generatePalindromes(pos + 1, n, number, k);
            start++;
        }

        // Reset the current position to ' ' (blank) after recursion
        number[pos] = ' ';
    }

public:
    // Main function to count all k-palindromes of length n
    long long countGoodIntegers(int n, int k) {
        // Initialize the factorial vector to store values from 0 to 10
        fact = vector<ll>(11);

        // Precompute factorials up to 10
        precomputeFactorial(n);

        // Create an empty string of length n
        string number(n, ' ');

        // Start the palindrome generation from position 0
        generatePalindromes(0, n, number, k);

        // Return the total count of k-palindromes found
        return k_palindromes;
    }
};
