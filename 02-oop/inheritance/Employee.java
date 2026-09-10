public class Employee {
    private final String name;

    public Employee(String name) {
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("Name is required.");
        }
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public String describeRole() {
        return name + " is an employee.";
    }

    public static void main(String[] args) {
        Employee employee = new Developer("Bob");

        System.out.println(employee.describeRole());

        String expected = "Bob develops software.";
        if (!expected.equals(employee.describeRole())) {
            throw new AssertionError("Unexpected role description.");
        }

        System.out.println("PASS");
    }

    private static final class Developer extends Employee {
        private Developer(String name) {
            super(name);
        }

        @Override
        public String describeRole() {
            return getName() + " develops software.";
        }
    }
}
