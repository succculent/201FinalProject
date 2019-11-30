package ProjectServer;

//need to include mysql connector jars, GOOGLE_APPLICATION_CREDENTIALS json
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class PacketServer {
	public PacketServer() {
		
		try {
			DatagramSocket ds = new DatagramSocket(42069);
			byte[] recv = new byte[65535];
			DatagramPacket dp = null;

			Connection conn = DriverManager.getConnection("jdbc:mysql://google/Project?cloudSqlInstance=myvirus:us-west1:myvir-database&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=root&password=root");

			while(true) {
				dp = new DatagramPacket(recv, recv.length);
				ds.receive(dp);

				new HashAccept(conn, dp);

				recv = new byte[65535];
			}
		}
		catch (SQLException sqle) {
			System.out.println(sqle.getMessage());
		}
		catch (IOException ioe) {
			System.out.println(ioe.getMessage());
		}
	}

	public static void main(String args[]) {
		new PacketServer();
	}
}