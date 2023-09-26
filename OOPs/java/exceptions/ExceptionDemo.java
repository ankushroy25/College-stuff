package exceptions;

import java.util.Scanner;

public class ExceptionDemo {
    public static void main(String[] args) {
        // ArrayIndexOutOfBoundsException
        try {
            int[] arr = new int[5];
            int element = arr[6];
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException caught");
        }

        // NullPointerException
        try {
            String str = null;
            int length = str.length();
        } catch (NullPointerException e) {
            System.out.println("NullPointerException caught");
        }

        // ArithmeticException
        try {
            int result = 5 / 0;
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException caught");
        }

        // NumberFormatException
        try {
            String str = "abc";
            int num = Integer.parseInt(str);
        } catch (NumberFormatException e) {
            System.out.println("NumberFormatException caught");
        }

        // ClassCastException
        try {
            class Parent {
            }
            class Child extends Parent {
            }
            Parent parent = new Parent();
            Child child = (Child) parent;
        } catch (ClassCastException e) {
            System.out.println("ClassCastException caught");
        }

        // InputMismatchException
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter an integer: ");
            int num = scanner.nextInt();
        } catch (java.util.InputMismatchException e) {
            System.out.println("InputMismatchException caught");
        }

        // IllegalStateException
        try {
            class MyState {
                private boolean state = false;

                public void changeState() {
                    if (state) {
                        throw new IllegalStateException("State is already true");
                    }
                    state = true;
                }
            }

            MyState myState = new MyState();
            myState.changeState();
            myState.changeState(); // Calling it twice will throw IllegalStateException
        } catch (IllegalStateException e) {
            System.out.println("IllegalStateException caught");
        }
    }
}
