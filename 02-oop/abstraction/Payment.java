public final class Payment {
    private Payment() {
    }

    public static abstract class PaymentMethod {
        private final String owner;

        protected PaymentMethod(String owner) {
            if (owner == null || owner.isBlank()) {
                throw new IllegalArgumentException("Owner is required.");
            }
            this.owner = owner;
        }

        protected final String getOwner() {
            return owner;
        }

        public abstract String pay(double amount);

        protected static void validateAmount(double amount) {
            if (amount <= 0.0) {
                throw new IllegalArgumentException("Amount must be positive.");
            }
        }
    }

    public static final class CardPayment extends PaymentMethod {
        public CardPayment(String owner) {
            super(owner);
        }

        @Override
        public String pay(double amount) {
            validateAmount(amount);
            return getOwner() + " paid " + amount + " by card.";
        }
    }

    public static final class CashPayment extends PaymentMethod {
        public CashPayment(String owner) {
            super(owner);
        }

        @Override
        public String pay(double amount) {
            validateAmount(amount);
            return getOwner() + " paid " + amount + " in cash.";
        }
    }

    public static void main(String[] args) {
        PaymentMethod card = new CardPayment("Carol");
        PaymentMethod cash = new CashPayment("Dan");

        String cardResult = card.pay(25.0);
        String cashResult = cash.pay(10.0);

        System.out.println(cardResult);
        System.out.println(cashResult);

        if (!"Carol paid 25.0 by card.".equals(cardResult)) {
            throw new AssertionError("Unexpected card payment result.");
        }

        if (!"Dan paid 10.0 in cash.".equals(cashResult)) {
            throw new AssertionError("Unexpected cash payment result.");
        }

        System.out.println("PASS");
    }
}
