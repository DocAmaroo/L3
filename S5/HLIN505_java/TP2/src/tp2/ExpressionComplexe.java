package tp2;

public class ExpressionComplexe extends Nombre{
	private Nombre c1;
	private Nombre c2;
	private char op;
	
	public ExpressionComplexe(Nombre c1, Nombre c2, char op){
		this.c1 = c1;
		this.c2 = c2;
		this.op = op;
	}
	
	public double eval(){
		double res = 0;
		switch (op) {
			case '+':
				res = c1.eval() + c2.eval();
				break;
			case '-':
				res = c1.eval() - c2.eval();
				break;
			case '*':
				res = c1.eval() * c2.eval();
				break;
			case '/':
				res = c1.eval() / c2.eval();
				break;
			default:
				break;
			}
		
		return res;
	}
	
	public String toString(){
		return c1.toString() + " " + op + " " + c2.toString();
	}
}
