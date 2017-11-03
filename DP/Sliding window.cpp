/**
    * Sliding window algorithm for range mini-max
    * Complexity: O(n)
*/

typedef vector<int> vi;
vi in(MAX);

vi sliding_window(int n, int w,bool isMin)
{

    std::deque< std::pair<int, int> > window;
    vi slide;
    for (int i = 0; i < n; i++)
    {
        if(isMin)
        {
            while (!window.empty() && window.back().first >= in[i])
                window.pop_back();
        }
        else
        {
            while (!window.empty() && window.back().first <= in[i])
                window.pop_back();
        }

        window.push_back(std::make_pair(in[i], i));

        while(window.front().second <= i - w)
            window.pop_front();

        slide.push_back(window.front().first);
    }

    return slide;
}
