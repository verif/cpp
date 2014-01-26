public static List<Integer> getCoinSet(int S, int[] coins) {
    List<Integer> coinsSet = new LinkedList<Integer>();
    if (S <= 0) return coinsSet;

    int[] coinSumArr = buildCoinstArr(S, coins);

    if (coinSumArr[S] < 0) throw new RuntimeException("Not possible to get given sum: " + S);

    int i = S;
    while (i > 0) {
        int coin = coins[coinSumArr[i]];
        coinsSet.add(coin);
        i -= coin;
    }

    return coinsSet;
}

public static int[] buildCoinstArr(int S, int[] coins) {
    Arrays.sort(coins);
    int[] result = new int[S + 1];

    for (int s = 1; s <= S; s++) {
        result[s] = -1;
        for (int i = coins.length - 1; i >= 0; i--) {
            int coin = coins[i];
            if (coin <= s && result[s - coin] >= 0) {
                result[s] = i;
                break;
            }
        }
    }

    return result;
}
