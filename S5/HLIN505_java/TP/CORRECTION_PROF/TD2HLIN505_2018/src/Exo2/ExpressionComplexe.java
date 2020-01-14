package Exo2;

public class ExpressionComplexe extends Operande{
	private Operande op1;
	private char op;
	private Operande op2;
	
	public ExpressionComplexe(Operande op1, char op, Operande op2) {
		this.op1 = op1;
		this.op = op;
		this.op2 = op2;
	}
	
	public float eval() {
		switch(op) {
		case '+' : return op1.eval() + op2.eval();
		
		case '-' : return op1.eval() - op2.eval();
		
		case '*' : return op1.eval() * op2.eval();
		
		case '/' : return op1.eval() / op2.eval();
		
		default : throw new RuntimeException("Unknown Operator");
		}
	}
}