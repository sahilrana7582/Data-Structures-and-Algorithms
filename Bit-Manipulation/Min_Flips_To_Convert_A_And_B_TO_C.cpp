class Solution {
    public:
        int minFlips(int a, int b, int c) {
            int ans = 0;
    
            while(a != 0 || b != 0 || c != 0) {  
                int lastBitA = a & 1;
                int lastBitB = b & 1;
                int lastBitC = c & 1;
    
                if (lastBitC == 1) { 
                    if (lastBitA == 0 && lastBitB == 0) {
                        ans += 1;  
                    }
                } else {  
                    if (lastBitA == 1 && lastBitB == 1) {
                        ans += 2;  
                    } else if (lastBitA == 1 || lastBitB == 1) {
                        ans += 1;  
                    }
                }
    
    
                a = a >> 1;
                b = b >> 1;
                c = c >> 1;
            }
    
            return ans;  
        }
    };
    