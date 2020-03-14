class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
    {
        for(int i=0;i<products.size();i++)
            product_prices[products[i]]=prices[i];
        this->n=n;
        temp=0;
        this->discount=discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) 
    {
        bill=0;
        for(int i=0;i<product.size();i++)
            bill+=product_prices[product[i]]*amount[i];
        temp=(temp+1)%n;
        if(!temp)
            bill=bill-(bill*discount)/100;
        return bill;
    }
    private:
    unordered_map<int,int> product_prices;
    int n,temp,discount;
    double bill;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */