#include <iostream>
using namespace std;

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

void knapsack_dynamic(int n, int capacity, int weights[], int profits[]) 
{
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) 
	{
        for (int w = 0; w <= capacity; w++) 
		{
            if (i == 0 || w == 0) 
			{
                dp[i][w] = 0;
            } 
			else if (weights[i - 1] <= w) 
			{
                dp[i][w] = max(dp[i - 1][w], profits[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } 
			else 
			{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int selected_items[n];
    int total_profit = dp[n][capacity];
    int w = capacity;
    int count = 0;

    for (int i = n; i > 0 && total_profit > 0; i--) 
	{
        if (total_profit == dp[i - 1][w]) 
		{
            continue;
        } 
		else 
		{
            selected_items[count++] = i;
            total_profit -= profits[i - 1];
            w -= weights[i - 1];
        }
    }

    cout << "Maximum Profit: " << dp[n][capacity] << endl;
    cout << "Selected Items: ";
    for (int i = count - 1; i >= 0; i--) 
	{
        cout << selected_items[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int n, capacity;
    cout << "Enter the number of objects: ";
    cin >> n;
    cout << "Enter the capacity of the bag: ";
    cin >> capacity;

    int weights[n], profits[n];

    cout << "Enter the weight and profit of each object:" << endl;
    for (int i = 0; i < n; i++) 
	{
        cin >> weights[i] >> profits[i];
    }

    knapsack_dynamic(n, capacity, weights, profits);

    return 0;
}
