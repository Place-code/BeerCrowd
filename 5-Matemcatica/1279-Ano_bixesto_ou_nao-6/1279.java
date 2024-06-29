import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		Scanner entrada = new Scanner(System.in);
		BigInteger numero;
		BigInteger b4 = new BigInteger("4");
		BigInteger b15 = new BigInteger("15");
		BigInteger b100 = new BigInteger("100");
		BigInteger b400 = new BigInteger("400");
		BigInteger b0 = new BigInteger("0");
		BigInteger b55 = new BigInteger("55");
		boolean bglbxs = false;
		boolean bglhullcus = false;
		boolean bglbucu = false;
		while (entrada.hasNext()) {
			numero = entrada.nextBigInteger();
			if ((((numero.mod(b4).equals(b0)) && (!numero.mod(b100).equals(b0))) || (numero.mod(b400).equals(b0)))) {
				bglbxs = true;
				if (numero.mod(b55).equals(b0)) {
					bglbucu = true;
				} else {
					bglbucu = false;
				}
			} else {
				bglbxs = false;
				bglbucu = false;
			}
			if (numero.mod(b15).equals(b0)) {
				bglhullcus = true;
			} else {
				bglhullcus = false;
			}
			if (bglbxs) {
				System.out.println("This is leap year.");
			}
			if (bglhullcus) {
				System.out.println("This is huluculu festival year.");
			}
			if (bglbucu) {
				System.out.println("This is bulukulu festival year.");
			}
			if (!(bglbxs || bglbucu || bglhullcus)) {
				System.out.println("This is an ordinary year.");
			}
			if (entrada.hasNext()) {
				System.out.println();
			}
		}
	}
}