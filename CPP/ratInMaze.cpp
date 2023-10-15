#include <vector>
#include <stack>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool isPath(vector<vector<int>> maze, Point start, Point end)
{
    stack<Point> s;
    s.push(start);

    while (!s.empty())
    {
        Point current = s.pop();

        if (current == end)
        {
            return true;
        }

        // Check if the current point is valid.
        if (current.x < 0 || current.x >= maze.size() || current.y < 0 || current.y >= maze[0].size() || maze[current.x][current.y] == 0)
        {
            continue;
        }

        // Mark the current point as visited.
        maze[current.x][current.y] = 0;

        // Add the adjacent points to the stack.
        s.push({current.x - 1, current.y});
        s.push({current.x + 1, current.y});
        s.push({current.x, current.y - 1});
        s.push({current.x, current.y + 1});
    }

    return false;
}

int main()
{
    vector<vector<int>> maze = {{1, 1, 0, 0}, {1, 1, 0, 1}, {1, 0, 0, 0}, {0, 1, 1, 1}};
    Point start = {0, 0};
    Point end = {3, 3};

    if (isPath(maze, start, end))
    {
        cout << "There is a path from the start to the end of the maze." << endl;
    }
    else
    {
        cout << "There is no path from the start to the end of the maze." << endl;
    }

    return 0;
}
