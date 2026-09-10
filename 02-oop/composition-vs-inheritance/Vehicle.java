public final class Vehicle {
    private Vehicle() {
    }

    public interface Engine {
        String start();
    }

    public static final class ElectricEngine implements Engine {
        @Override
        public String start() {
            return "Electric engine started.";
        }
    }

    public static final class PetrolEngine implements Engine {
        @Override
        public String start() {
            return "Petrol engine started.";
        }
    }

    public static final class Car {
        private final String model;
        private final Engine engine;

        public Car(String model, Engine engine) {
            if (model == null || model.isBlank()) {
                throw new IllegalArgumentException("Model is required.");
            }
            if (engine == null) {
                throw new IllegalArgumentException("Engine is required.");
            }

            this.model = model;
            this.engine = engine;
        }

        public String start() {
            return model + ": " + engine.start();
        }
    }

    public static void main(String[] args) {
        Car electricCar = new Car("Example EV", new ElectricEngine());
        Car petrolCar = new Car("Example Car", new PetrolEngine());

        String electricResult = electricCar.start();
        String petrolResult = petrolCar.start();

        System.out.println(electricResult);
        System.out.println(petrolResult);

        if (!"Example EV: Electric engine started.".equals(electricResult)) {
            throw new AssertionError("Unexpected electric-car result.");
        }

        if (!"Example Car: Petrol engine started.".equals(petrolResult)) {
            throw new AssertionError("Unexpected petrol-car result.");
        }

        System.out.println("PASS");
    }
}
