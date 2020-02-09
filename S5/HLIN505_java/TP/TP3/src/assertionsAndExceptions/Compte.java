package assertionsAndExceptions;

public class Compte {
	
	private int decouvert;
	private int solde;
	
	
	public Compte(int solde, int decouvert){
		setDecouvert(decouvert);
		setSolde(solde);
	}
	
	public void setDecouvert(int decouvert){
		assert (decouvert > 0);
		this.decouvert = decouvert;
	}
	
	public void setSolde(int solde){
		this.solde = solde;
	}
	
	public void crediter(int credit){
		assert(credit > 0);
		setSolde(solde + credit);
		System.out.println("Le nouveau solde est de : " + solde);
	}
	
	public String toString(){
		return "Solde = " + solde + " - Decouvert = " + decouvert;
	}
	

}
