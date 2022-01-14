#include<iostream>
#include<math.h>
void solve(double meal_cost, int tip_percent, int tax_percent) {
    double tip = (meal_cost/100)*tip_percent;
    printf("%0.1f\n",tip);
    double tax = ((double)tax_percent/100)*tip_percent;
    printf("%0.1f\n",tax);
    float total_cost = meal_cost + tip + tax;
    printf("%f",round(total_cost)); 
}

int main()
{
    solve(12.00,20,8);
    return 0;
}
