// Given N days to survive
// Given food required per day is M.
// Given each day you can buy K units of food
// Show is it possible to survive or not if yes then minimum number of days
// you have to buy food
// NOTE: You can not buy food on sunday
// You start with monday
// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

int canSurvive(int days_to_survive, int max_qty_buy_per_day, int consumption_per_day) {
    int total_sundays = days_to_survive / 7;
    int total_days_buyable = days_to_survive - total_sundays;
    int total_food = total_days_buyable * max_qty_buy_per_day;
    int total_food_required = days_to_survive * consumption_per_day;
    int min_days_baught = total_food_required / max_qty_buy_per_day;
    if (total_food < total_food_required) return -1;
    return (total_food_required % max_qty_buy_per_day == 0) ? min_days_baught : min_days_baught + 1;
}