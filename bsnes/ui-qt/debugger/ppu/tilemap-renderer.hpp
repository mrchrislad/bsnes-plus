struct TilemapRenderer {
  enum BitDepth { BPP8, BPP4, BPP2 };

  uint32_t palette[256];

  unsigned tileAddr;
  unsigned screenAddr;

  BitDepth bitDepth;
  bool screenSizeX;
  bool screenSizeY;
  bool tileSize;

public:
  TilemapRenderer();

  void buildPalette();

  QImage drawTilemap();

private:
  void drawMap(QImage& image, unsigned mapAddr, unsigned startX, unsigned startY);
  void drawMapTile(uint32_t* imgBits, const unsigned wordsPerScanline, const uint8_t* map);
  void draw8pxTile(uint32_t* imgBits, const unsigned wordsPerScanline, unsigned c, uint8_t pal, bool hFlip, bool vFlip);
};