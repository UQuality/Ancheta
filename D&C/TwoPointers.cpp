// Algorithm to find an exact number (target) as sum of two values (indexes i and j)

int i = 0, j = numbers.size() - 1;
while(i < j) {
    int current = numbers[i] + numbers[j];
    if(current == target) break;
    else if (current < target) i++;
    else j--;
}
