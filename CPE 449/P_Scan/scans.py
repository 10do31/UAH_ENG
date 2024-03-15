# Dan Otieno.
# CPE 449.
# Port Scan Detection Assignment.

import dpkt
import argparse

def fnPortScan(pcap_file):
    null_ports = set()
    xmas_ports = set()
    udp_ports = set()
    half_open_ports = set()
    connect_ports = set()

    with open(pcap_file, 'rb') as f:
        pcap = dpkt.pcap.Reader(f)

        for _, packet in pcap:
            eth = dpkt.ethernet.Ethernet(packet)

            if isinstance(eth.data, dpkt.ip.IP):
                ip = eth.data

                if isinstance(ip.data, dpkt.tcp.TCP):
                    tcp = ip.data

                    # Check for NULL scan
                    if tcp.flags == 0:
                        null_ports.add(tcp.dport)

                    # Check for XMAS scan (FIN, URG, PSH flags set)
                    elif tcp.flags & (dpkt.tcp.TH_FIN | dpkt.tcp.TH_URG | dpkt.tcp.TH_PUSH) == (dpkt.tcp.TH_FIN | dpkt.tcp.TH_URG | dpkt.tcp.TH_PUSH):
                        xmas_ports.add(tcp.dport)

                    # Check for Half-Open scan (SYN flag set)
                    elif tcp.flags & dpkt.tcp.TH_SYN != 0 and tcp.flags & dpkt.tcp.TH_ACK == 0:
                        half_open_ports.add(tcp.dport)

                    # Check for Connect scan (SYN, ACK flags set)
                    elif tcp.flags & (dpkt.tcp.TH_SYN | dpkt.tcp.TH_ACK) == (dpkt.tcp.TH_SYN | dpkt.tcp.TH_ACK):
                        connect_ports.add(tcp.dport)

                elif isinstance(ip.data, dpkt.udp.UDP):
                    udp = ip.data
                    udp_ports.add(udp.dport)

    return null_ports, xmas_ports, udp_ports, half_open_ports, connect_ports

def main():
    parser = argparse.ArgumentParser(description='Count unique scans and their scanned ports in a pcap file.')
    parser.add_argument('-i', '--input', type=str, required=True, help='Path to the pcap file')

    args = parser.parse_args()
    pcap_file_path = args.input

    try:
        null_ports, xmas_ports, udp_ports, half_open_ports, connect_ports = fnPortScan(pcap_file_path)

        print(f"Null: {len(null_ports)}" if "nullscan" in pcap_file_path.lower() else "Null: Not counted.")
        print(f"XMAS: {len(xmas_ports)}" if "xmasscan" in pcap_file_path.lower() else "XMAS: Not counted.")
        print(f"UDP: {len(udp_ports)}" if "udpscan" in pcap_file_path.lower() else "UDP: Not counted.")
        print(f"Half-open: {len(half_open_ports)}" if "synscan" in pcap_file_path.lower() else "Half-open: Not counted.")
        print(f"Connect: {len(connect_ports)}" if "connectscan" in pcap_file_path.lower() else "Connect: Not counted.")

    except dpkt.dpkt.NeedData:
        print("Error!! Packet Parsing failed!")

if __name__ == "__main__":
    main()
