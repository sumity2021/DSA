class Bank {
    vector<long long>bal;
    
public:
    Bank(vector<long long>& balance) {
        this->bal=balance;

    }
    
    bool transfer(int account1, int account2, long long money) {
        int size=bal.size();
        if(account1>size || account2>size) return 0;
        if(bal[account1-1]-money<0) return 0;
        bal[account1-1]-=money;
        bal[account2-1]+=money;
        return 1;
    }
    
    bool deposit(int account, long long money) {
        int size=bal.size();
        if(account>size) return 0;
        bal[account-1]+=money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        int size=bal.size();
        if(account>size) return 0;
        if(bal[account-1]-money<0) return 0;
        bal[account-1]-=money;
        return 1;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */