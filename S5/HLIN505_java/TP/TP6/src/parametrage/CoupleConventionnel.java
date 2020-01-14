package parametrage;

public class CoupleConventionnel<A extends Male, B extends Femelle> extends Paire<A, B> {

	public CoupleConventionnel() {
		super();
	}

	public CoupleConventionnel(A a, B b) {
		super(a, b);
	}
}