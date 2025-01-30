class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            vector<pair<int , int>> vec;

            for(int i=0 ; i<profits.size() ; i++){
                vec.push_back({ capital[i] , profits[i]});
            }       

            sort(begin(vec) , end(vec));

            priority_queue<int> pq;

            int indx = 0;

            while(k--){

                while(indx<vec.size() && vec[indx].first<=w){
                    pq.push(vec[indx].second);
                    indx++;
                }
        
                if (pq.empty()) {
                        break;
                }
                
                w += pq.top();
                pq.pop(); 

            }

        return w;
    }
};