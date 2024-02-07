#pragma once
#include "BRP.h"

class BRP_human_AncientEra : public BRP_human_base {
public:
  BRP_human_AncientEra(int a, int b, int c, int d, int e, int x, int y, int z);
  void Skills(int stat_dex, int stat_int, int stat_pow) override;

  ~BRP_human_AncientEra() {};
};