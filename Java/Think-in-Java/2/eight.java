class StaticTest {
	static int i = 47;
}

class Incrementable {
	static void increment() { StaticTest.i++; }
}

public class eight {
	public static void main(String[] args) {
		System.out.println("StaticTest.i= " + StaticTest.i);
		StaticTest st1 = new StaticTest();
		StaticTest st2 = new StaticTest();
		System.out.println("st1.i= " + i);
		System.out.println("st2.i= " + i);
		Incrementable.increment();
		System.out.println("After Incrementable.increment() called: ");
		System.out.println("st1.i = " + i);
		System.out.println("st2.i = " + i);
		Incrementable.increment();
		System.out.println("After Incrementable.increment called: ");
		System.out.println("st1.i = " + i);
		System.out.println("st2.i = " + i);
		i = 3;
		System.out.println("After st1.i = 3, ");
		System.out.println("st1.i = " + i);
		System.out.println("st2.i = " + i);
		System.out.println("Create another StaticTest, st3.");
		StaticTest st3 = new StaticTest();
		System.out.println("st3.i = " + i);
	}
}