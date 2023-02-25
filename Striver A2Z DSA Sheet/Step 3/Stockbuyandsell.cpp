// Problem Link: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/0?company[]=Intuit+&page=1&query=company[]Intuit+page1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stock-buy-and-sell

void stockBuySell(int price[], int n) {
    int buy, sell;
    int i = 0;
    int count = 0;
    while(i < n - 1) {
       while(i < n - 1 && price[i + 1] < price[i])
           i++;
       buy = i;
       i++;
       
       while(i < n && price[i] > price[i - 1])
           i++;
       sell = i - 1;
       
       if(price[buy] < price[sell]) {
           count++;
           cout<<"("<<buy<<" "<<sell<<")"<<" ";
       }
   }
   if(count == 0)
       cout<<"No Profit";
   cout<<endl;
}