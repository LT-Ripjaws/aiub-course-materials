#include <iostream>
using namespace std;

    struct Item
    {
        int weight;
        int profit;
    };

    void fractionalKnapsack(int n, int capacity, int weights[], int profits[])
    {

        Item items[n];

        for (int i = 0; i < n; i++)
        {
            items[i].weight = weights[i];
            items[i].profit = profits[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if ((double)items[j].profit / items[j].weight < (double)items[j + 1].profit /
                    items[j + 1].weight)
                    {
                        swap(items[j], items[j + 1]);
                    }
            }
        }

        int currentWeight = 0;
        double totalProfit = 0.0;

        bool taken[n];

        fill(taken, taken + n, false);

        for (int i = 0; i < n; i++)
        {
            if (currentWeight + items[i].weight <= capacity)
            {

                currentWeight += items[i].weight;
                totalProfit += items[i].profit;
                taken[i] = true;
            }
            else
            {

                double remainingWeight = capacity - currentWeight;
                totalProfit += (double)items[i].profit / items[i].weight * remainingWeight;
                break;
            }

            cout << "Maximum Profit: " << totalProfit << endl;
            cout << "Objects Taken: ";
            for (int i = 0; i < n; i++)
            {
                if (taken[i])
                {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
        }
    }

int main()
{
    int n;
    int capacity;

    cout << "Enter the number of objects: ";
    cin >> n;
    cout << "Enter the knapsack size: ";
    cin >> capacity;
    int weights[n];
    int profits[n];

    cout << "Enter the weights of objects: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter the profits of objects: ";
    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
    }

    fractionalKnapsack(n, capacity, weights, profits);
    return 0;
}
