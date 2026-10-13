import matplotlib.pyplot as plt

# Data points from the table
freq = [100, 300, 500, 600, 700, 800, 900, 1000, 1591.55, 2000, 3000, 5000, 8000, 10000, 15000, 20000]
gain_db = [0.66, 0.34, 0.34, 0.34, 0.34, 0.34, 0.34, 0.0, -1.11, -1.93, -2.88, -5.69, -7.95, -7.95, -12.35, -12.35]

plt.figure(figsize=(10, 6))
plt.semilogx(freq, gain_db, 'ro-', label='Filter Response', linewidth=2, markersize=5)

plt.title('Filter Characteristic Curve (Gain vs Frequency)', fontsize=14)
plt.xlabel('Frequency (Hz) [Logarithmic Scale]', fontsize=12)
plt.ylabel('Gain (dB)', fontsize=12)

plt.axhline(0, color='black', linewidth=0.8)
plt.axhline(-3, color='blue', linestyle='--', label='-3 dB Cutoff Threshold')
plt.grid(True, which="both", ls="--", color='gray', alpha=0.6)

plt.legend()
plt.tight_layout()
plt.show()
