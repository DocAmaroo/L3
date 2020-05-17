package tp2;

public class Constante extends Nombre{
	
	private double nombre;
	
	public Constante(double nombre){
		this.nombre = nombre;
	}
	
	public double eval(){
		return nombre;
	}
	
	public String toString(){
		return nombre + "";
	}
	
}
