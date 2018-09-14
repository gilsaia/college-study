class twentytwo
{
    public enum money
    {
        ONE_CENT,TWO_CENT,THREE_CENT,FOUR_CENT,FIVE_CENT,SIX_CENT
    }
    public static void main(String[] args) {
        for(money ss:money.values())
        {
            switch(ss)
            {
                case ONE_CENT:System.out.println("This is one cent");
                break;
                case TWO_CENT:System.out.println("This is two cent");
                break;
                case THREE_CENT:System.out.println("This is three cent");
                break;
                case FOUR_CENT:System.out.println("This is four cent");
                break;
                case FIVE_CENT:System.out.println("This is five cent");
                break;
                case SIX_CENT:System.out.println("This is six cent");
                break;
                default:System.out.println("This is no cent");
            }
        }
    }
}