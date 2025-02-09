class NumberContainers {
    map<int, int> mpp;
    map<int, priority_queue<int, vector<int>, greater<int>>> mpp1;


public:
    NumberContainers() { }

    void change(int index, int number) {
        mpp[index] = number;
        mpp1[number].push(index);
    }

    int find(int number) {
        while(!mpp1[number].empty()){
            int idx = mpp1[number].top();

            if(mpp[idx] == number){
                return idx;
            }

            mpp1[number].pop();
        }

        return -1;
    }
};
