class Solution {
public:
    // long long ncr(int r, int c){
    //     long long ans = 1;
    //     for (int i = 0; i < c; i++){
    //         ans = ans * (r - i)/(i + 1);
    //     }//4/1 * 3/2 = 6
    //     //4/1 * 3/2 * 2/3 * 1 / 4
    //     return ans;
    // }

    vector<int> generate_row(int row_num)
{
    vector<int> pascal_row(row_num, 0);
    pascal_row[0] = 1;
    int num;
    int den;

    for (int i = 1; i < row_num; i++)
    {
        num = (row_num - i);
        den = i;

        pascal_row[i] = (pascal_row[i - 1] * num) / den;
    }

    return pascal_row;
}

    vector<vector<int>> generate(int numRows) {
        //somwhat ok soln

    //     vector<vector<int>> pascal_triangle;
    //     for (int i = 0; i < numRows; i++){
    //         vector<int> row;
    //         cout << i << endl;
    //         for (int j = 0; j <= i; j++){
    //             //j = 0 ans = 1 row = [1]
    //             // j = 1 ans = 4 row = [1 4]
    //             // j = 2 ans = 6 row = [1 4 6]
    //             // j = 3 ans = 4 row = [1 4 6 4]
    //             // j = 4 ans = 1 row = [1 4 6 4 1]
    //             row.push_back(ncr(i, j));
    //             //     // cout << i << endl;
    //             //     cout << row[k] << " ";
    //             //     // cout << endl;
    //             // }));
    //             cout << "i: " << i << endl;
    //             cout << "j: " << j << endl;
    //             cout << "ncr val: " << ncr(i, j);
    //             // 
    //             cout << endl;

    //         }
    //         pascal_triangle.push_back(row);
    //     }

    //     return pascal_triangle;

    // optimal
        vector<vector<int>> pascal_triangle;
        for (int i = 1; i <= numRows; i++){
            pascal_triangle.push_back(generate_row(i));
        }
        return pascal_triangle;
    }
};