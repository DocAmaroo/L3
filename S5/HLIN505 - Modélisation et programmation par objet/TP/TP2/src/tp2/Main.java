package tp2;

public class Main {

	public static void main(String argv[]){
		Constante c1 = new Constante(5);
		Constante c2 = new Constante(2);
		Constante c3 = new Constante(3);
		
		ExpressionComplexe ec1 = new ExpressionComplexe(c1, c2, '+');
		ExpressionComplexe ec2 = new ExpressionComplexe(ec1,c3, '*');
		ExpressionComplexe ec3 = new ExpressionComplexe(new Constante(4), ec2, '*');
		
		System.out.println(c1.eval());
		System.out.println(ec1.eval());
		System.out.println(ec2.eval());
		System.out.println(ec3.eval());
		
		Object ec4 = new Constante(84);
		System.out.println(ec3.equals(ec4));
	}
}
