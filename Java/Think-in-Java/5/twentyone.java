class twentyone
{
    public enum money
    {
        ONE_CENT,TWO_CENT,THREE_CENT,FOUR_CENT,FIVE_CENT,SIX_CENT
    }
    public static void main(String[] args) {
        for(money ss:money.values())
        {
            System.out.println(ss+".num "+ss.ordinal());
        }
    }
}