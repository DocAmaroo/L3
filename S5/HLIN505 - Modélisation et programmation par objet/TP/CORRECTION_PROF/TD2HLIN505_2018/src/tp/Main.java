package tp;

public class Main {

	public static void main(String[] args) {
		Livre l1=new Livre("l1", 3);
		Document l2=new Livre("l2", 4);
		
		Document d=new Document("d");
		
		Biblio b =new Biblio();
		BiblioSansDoublons bsd=new BiblioSansDoublons();
		Biblio bsd2=new BiblioSansDoublons();
		
		// ajout dans b:Biblio
		/*b.ajoutDocument(l1);
		b.ajoutDocument(l1);
		b.ajoutDocument(l2);
		b.ajoutDocument(d);
		System.out.println(b.toString());
		//	ajout dans bsd:BiblioSansDoublons
		bsd.ajoutDocument(l1);
		bsd.ajoutDocument(l1);
		bsd.ajoutDocument(l2);
		bsd.ajoutDocument(d);
		System.out.println(bsd.toString());
		//	ajout dans bsd2:BiblioSansDoublons
		bsd2.ajoutDocument(l1);
		bsd2.ajoutDocument(l1);*/
		bsd2.ajoutDocument(l2);
		//bsd2.ajoutDocument(d);
		System.out.println(bsd2.toString());
	}

}