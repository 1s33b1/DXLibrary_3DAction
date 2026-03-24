#pragma once
namespace ScreenSettings {
	const int screenWidth = 800;
	const int screenHeight = 600;
	const int screenColorBit = 16;
}

namespace BulletSettings {
	const int bulletLimit = 10;
}

namespace EnemySettings {
	const int enemyLimit = 5; // “G‚ğ¶¬‚·‚éŒÀŠE’l
	const int firstEnemyPosx = 100;
	const int firstEnemyPosy = -50;
	const int intervalSpace = 30; // “G‚Æ“G‚ğ•À‚×‚é‚Æ‚«‚ÌŠÔŠu
	const int enemyBulletLimit = 5;
}

namespace ExplosionSettings {
	const int divisionNum = 11; // ‰æ‘œ‚ğ•ªŠ„‚·‚é‚Æ‚«‚ÌŒÂ”B
}

namespace PlayerSettings {
	const float StartPos = 0; // ˆê’è‚Ì
	const int playerSpeed = 5;
}

// ‚±‚ÌF‚Ì”’l‚½‚¿‚Í‰½‚©‚µ‚çˆá‚¤Œ`‚Å‚¢‚¢Š´‚¶‚É‚Ü‚Æ‚ß‚½‚¢
namespace ColorSettings {
	const int Red_r = 255;
	const int Red_g = 0;
	const int Red_b = 0;

	const int Blue_r = 0;
	const int Blue_g = 255;
	const int Blue_b = 0;

	const int Green_r = 0;
	const int Green_g = 0;
	const int Green_b = 255;
}

namespace GroundSettings{
	const int groundMax = 4; // •`‰æ‚·‚é’n–Ê‚ÌÅ‘åŒÂ”
	const float cx = 100.0f;
	const float cy = 100.0f;
	const float size = 100.0f;
	const float angle = 0.0f;
}