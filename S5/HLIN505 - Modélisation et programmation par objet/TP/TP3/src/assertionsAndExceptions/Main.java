package assertionsAndExceptions;

public class Main {
	public static void main(String[] args){
//		ListeChainee l = new ListeChainee();
//		ListeChainee.Node racine = l.new Node("racine");
//		ListeChainee.Node n1 = l.new Node("Node 1",racine);
//		ListeChainee.Node n2 = l.new Node("Node 2",n1);
//		l.ajouterEnTete(racine);
//		l.ajouterEnTete(n1);
//		l.ajouterEnTete(n2);
//		System.out.println(l);
//		System.out.println(l.reverse());

		Compte c1 = new Compte(69, 1000);
		System.out.println(c1);
		c1.crediter(0);
	}
}
