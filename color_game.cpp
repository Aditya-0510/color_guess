#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    vector<int> color{1, 2, 3};
    vector<int> user;
    int c_count;
    int random_number{};

    srand(time(nullptr));

    random_shuffle(color.begin(), color.end());

    std::cout << "Instructions:\n1 is for Red\n2 is for Blue\n3 is for Yellow\n4 is for Green";

    int val{0};
    int k{3};
    while (true)
    {
        c_count = 0;
        std::cout << "Guess your order of colors for round " << k - 2 << " : ";
        user.clear();
        for (int i = 0; i < k; i++)
        {
            std::cin >> val;
            user.push_back(val);
        }
        vector<int> hint;
        for (int i = 0; i < k; i++)
        {
            if (color.at(i) == user.at(i))
            {
                hint.push_back(i + 1);
                c_count++;
            }
        }
        if (c_count == k)
        {
            std::cout << "You have guessed all correct" << endl;
            k++;
            color.push_back(k);
            random_shuffle(color.begin(), color.end());
            std::cout << "Proceeding to the next round" << endl;
            continue;
        }
        char ch{};
        std::cout << "You have guessed " << c_count << " correct" << endl;
        std::cout << "Do you want hint(y/n)?: ";
        std::cin >> ch;

        if (ch == 'y')
        {
            std::cout << "The number at ";
            for (auto i : hint)
                std::cout << i << " ";
            std::cout << " position is/are correct" << endl;
        }
    }

    return 0;
}
