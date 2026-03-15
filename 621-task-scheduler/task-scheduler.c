int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    // Count frequencies
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find max frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    // Count how many tasks have max frequency
    int countMaxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            countMaxFreq++;
        }
    }

    // Apply formula
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int minTime = partCount * partLength + countMaxFreq;

    return (tasksSize > minTime) ? tasksSize : minTime;
}