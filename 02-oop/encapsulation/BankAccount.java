public final class BankAccount {
    private final String owner;
    private double balance;

    public BankAccount(String owner, double initialBalance) {
        if (owner == null || owner.isBlank()) {
            throw new IllegalArgumentException("Owner is required.");
        }
        if (initialBalance < 0.0) {
            throw new IllegalArgumentException("Initial balance cannot be negative.");
        }

        this.owner = owner;
        this.balance = initialBalance;
    }

    public String getOwner() {
        return owner;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        validatePositiveAmount(amount);
        balance += amount;
    }

    public void withdraw(double amount) {
        validatePositiveAmount(amount);

        if (amount > balance) {
            throw new IllegalArgumentException("Insufficient balance.");
        }

        balance -= amount;
    }

    private static void validatePositiveAmount(double amount) {
        if (amount <= 0.0) {
            throw new IllegalArgumentException("Amount must be positive.");
        }
    }

    public static void main(String[] args) {
        BankAccount account = new BankAccount("Alice", 100.0);

        account.deposit(50.0);
        account.withdraw(30.0);

        System.out.println("Owner: " + account.getOwner());
        System.out.println("Balance: " + account.getBalance());

        if (Double.compare(account.getBalance(), 120.0) != 0) {
            throw new AssertionError("Unexpected final balance.");
        }

        System.out.println("PASS");
    }
}
