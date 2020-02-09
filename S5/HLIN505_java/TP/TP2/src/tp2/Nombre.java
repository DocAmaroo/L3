package tp2;

public abstract class Nombre {
	public abstract double eval();
	
	public boolean equals(Object o){
		if (!(o instanceof Nombre)) return false;
		return eval() == ((Nombre) o).eval();
	}
}
