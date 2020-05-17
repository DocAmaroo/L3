package td3.ex3;


public class Constante extends Operande {
	private float number;
	
	public Constante(float number) {
		this.number = number;
	}
	
	public float eval() {
		return number;
	}
}
