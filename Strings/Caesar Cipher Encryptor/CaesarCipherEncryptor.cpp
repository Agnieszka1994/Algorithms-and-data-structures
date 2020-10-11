using namespace std;

string caesarCypherEncryptor(string str, int key) {
	string encrypted = str;
	int newKey = key%26;
	for (int i = 0; i < encrypted.length(); i++) {
		if (encrypted[i] + newKey <= 122) {
			encrypted[i] = encrypted[i] + newKey;
		}
		else {
			encrypted[i] = (96 + (encrypted[i] + newKey) % 122);
		}
	}
	return encrypted;
}