
class NumberChecker {
    
   
    public boolean isEven(int num) {
        return num % 2 == 0;
    }
    
    
    public boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
}


public class Main {
    private static NumberChecker checker = new NumberChecker();
    private static int testsPassed = 0;
    private static int totalTests = 0;

    public static void main(String[] args) {
        System.out.println("--- Starting NumberChecker Tests ---\n");

        runTest("Test Even Numbers", () -> {
            assert checker.isEven(2);
            assert checker.isEven(4);
            assert checker.isEven(100);
        });

        runTest("Test Odd Numbers", () -> {
            assert !checker.isEven(1);
            assert !checker.isEven(3);
            assert !checker.isEven(99);
        });

        runTest("Test Prime Numbers", () -> {
            assert checker.isPrime(2);
            assert checker.isPrime(3);
            assert checker.isPrime(5);
            assert checker.isPrime(17);
        });

        runTest("Test Non-Prime Numbers", () -> {
            assert !checker.isPrime(1);
            assert !checker.isPrime(4);
            assert !checker.isPrime(9);
            assert !checker.isPrime(15);
        });

        runTest("Test Negative Numbers", () -> {
            assert !checker.isPrime(-5);
        });

        System.out.println("\n--- Final Results ---");
        System.out.println("Tests Passed: " + testsPassed + "/" + totalTests);
    }

  

    private static void runTest(String testName, Runnable testLogic) {
        totalTests++;
        try {
            testLogic.run();
            System.out.println("[PASS] " + testName);
            testsPassed++;
        } catch (AssertionError e) {
            System.out.println("[FAIL] " + testName);
        } catch (Exception e) {
            System.out.println("[ERROR] " + testName + ": " + e.getMessage());
        }
    }
}
