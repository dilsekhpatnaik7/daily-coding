// Problem Link: https://practice.geeksforgeeks.org/problems/1646a9b5169d7571cf672f2a31533af083d1f479/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{   
  public:
  
    bool isprime(string s){
        int val = stoi(s);
        for(int i=2; i*i <= val; i++){
            if(val%i == 0){return false;}
        }
        return true;
    }
  
    int shortestPath(int Num1,int Num2){   
        string a, b;
        a = to_string(Num1); 
        b = to_string(Num2);
        
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(a);
        int ans = 0;
        if(Num1 == Num2){return ans;}
        visited[a] = true;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                string t = q.front();
                q.pop();
                if(t == b){return ans;}
                for(int d = 0; d < 4; d++){
                    for(int v = 0; v < 10; v++){
                        if(v == 0 && d == 0){continue;}
                        string temp = t;
                        temp[d] = to_string(v)[0];
                        if(isprime(temp) && visited[temp] == false){
                            q.push(temp);
                            visited[temp] = true;
                        }
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};