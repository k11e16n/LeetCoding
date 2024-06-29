/* Discussion:
haypieman
Oct 17, 2020
So remember that this is a combination of steps; NOT the number of steps.

Consider drawing a staircase and putting the number of combinations to make it easier.

So n[i-1] is the number of COMBINATIONS to get the the last stair. Now realize that you only need extra step to get to the ith stair. Now if you are thinking about n[i-1] + 1, it is wrong because you are thinking of the number of steps, not the number of combinations.

Let's make the problem easier: You HAVE to take ONE step, not two, on the LAST step. Imagine i is 6, and you are on the 5nd step, and now just say, that when you go from the 5th step to the 6th step, you will ALWAYS just take one more step to go to the 6th step, thus the number of combinations stays the SAME. Because all the combinations where you go to the 5th step, you are just taking another step, meaning the combination for all the 6th step will be the same as the 5th step, only you are taking another step at the end, and since it's # of combinations, not # of steps.

Now going back to the solution: n[i] = n[i-1] + n[i-2], realize that you also have to take in account for the fact that someone can go up 2 steps from i-2th step to ith step. Thus that's why you add n[i-2], because it's the same inituition. If you can only take a double step at the end, then the # of combinations will just be n[i-2] because it's the same combination as n[i-2] except you just taking 2 more steps at the end.

Since you can take 1 step at the end or 2 steps at the end, adding the two situtations together, it is n[i] = n[i-1] + n[i-2].
*/
#define METHOD 2

#if METHOD == 1 // recursive
int climbStairs(int n) {
    if(n <= 2 ){
        return n;
    }else{
        return climbStairs(n-1)+climbStairs(n-2);
    }
}
#endif

#if METHOD == 2 // loop
int climbStairs(int n) {
    if(n<=1) return 1;
    int result=0, first=1, second = 1;
    for(int i = 2;i<=n;i++)
    {
        result = first+second;
        first = second;
        second = result;
    }
    return result;
}
#endif
